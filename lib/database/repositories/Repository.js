/**
 * @license
 * Copyright CERN and copyright holders of ALICE O2. This software is
 * distributed under the terms of the GNU General Public License v3 (GPL
 * Version 3), copied verbatim in the file "COPYING".
 *
 * See http://alice-o2.web.cern.ch/license for full licensing information.
 *
 * In applying this license CERN does not waive the privileges and immunities
 * granted to it by virtue of its status as an Intergovernmental Organization
 * or submit itself to any jurisdiction.
 */

const {
    utilities: {
        QueryBuilder,
    },
} = require('../');

/**
 * Sequelize implementation of the Repository.
 */
class Repository {
    /**
     * Creates a new `Repository` instance.
     *
     * @param {*} model The database model to use.
     * @param {*} adapter The adapter related to the database model to use.
     */
    constructor(model, adapter) {
        this.model = model;
        this.adapter = adapter;
    }

    /**
     * Returns the total number of entities.
     *
     * @returns {Promise<Number>} Promise object representing the total number of entities.
     */
    async count() {
        return this.model.count();
    }

    /**
     * Returns all entities.
     *
     * @param {QueryBuilder} queryBuilder The QueryBuilder to use.
     * @returns {Promise} Promise object representing the full mock data
     */
    async findAll(queryBuilder = new QueryBuilder()) {
        return this.model.findAll(queryBuilder.toImplementation()).map(this.adapter.toEntity);
    }

    /**
     * Returns all entities.
     *
     * @param {QueryBuilder} queryBuilder The QueryBuilder to use.
     * @returns {Promise} Promise object representing the full mock data
     */
    async findAndCountAll(queryBuilder = new QueryBuilder()) {
        queryBuilder.set('distinct', true);

        const { count, rows } = await this.model.findAndCountAll(queryBuilder.toImplementation());
        return {
            count,
            entities: rows.map(this.adapter.toEntity),
        };
    }

    /**
     * Returns a specific entity.
     *
     * @param {QueryBuilder} queryBuilder The QueryBuilder to use.
     * @returns {Promise|Null} Promise object representing the full mock data
     */
    async findOne(queryBuilder = new QueryBuilder()) {
        queryBuilder.limit(1);
        const result = await this.model.findOne(queryBuilder.toImplementation());
        return result ? this.adapter.toEntity(result) : null;
    }

    /**
     * Insert entity.
     *
     * @param {Object} entity entity to insert.
     * @returns {Promise} Promise object represents the just inserted this.model.
     */
    async insert(entity) {
        const result = await this.model.create(this.adapter.toDatabase(entity));
        return this.adapter.toEntity(result);
    }

    /**
     * Removes a specific entity.
     *
     * @param {QueryBuilder} queryBuilder The QueryBuilder to use.
     * @returns {Promise|Null} Promise object representing the full mock data
     */
    async removeOne(queryBuilder = new QueryBuilder()) {
        queryBuilder.limit(1);

        const entity = await this.findOne(queryBuilder);
        if (entity) {
            await this.model.destroy(queryBuilder.toImplementation());
        }

        return entity;
    }
}

module.exports = Repository;