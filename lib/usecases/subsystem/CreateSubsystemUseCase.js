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
    repositories: {
        SubsystemRepository,
    },
    utilities: {
        QueryBuilder,
        TransactionHelper,
    },
} = require('../../database');

/**
 * CreateSubsystemUseCase
 */
class CreateSubsystemUseCase {
    /**
     * Executes this use case.
     *
     * @param {Object} dto The CreateSubsystemDto containing all data.
     * @returns {Promise} Promise object represents the result of this use case.
     */
    async execute(dto) {
        const queryBuilder = new QueryBuilder();
        const { body } = dto;

        queryBuilder.where('name').is(body.name);

        return TransactionHelper.provide(async () => {
            const subsystem = await SubsystemRepository.findOne(queryBuilder);
            if (subsystem) {
                return null;
            }

            return SubsystemRepository.insert(body);
        });
    }
}

module.exports = CreateSubsystemUseCase;