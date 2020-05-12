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

const Joi = require('@hapi/joi');
const PaginationDto = require('./PaginationDto');

const CustomJoi = Joi.extend({
    base: Joi.array(),
    type: 'stringArray',
    coerce: (value) => ({ value: value.split ? value.split(',') : value }),
});

const FilterDto = Joi.object({
    origin: Joi.string()
        .valid('human', 'process'),
});

const QueryDto = Joi.object({
    filter: FilterDto,
    page: PaginationDto,
    sort: CustomJoi.stringArray()
        .items(Joi.string()
            .valid('id', '-id')
            .valid('title', '-title')),
    token: Joi.string(),
});

const GetAllLogsDto = Joi.object({
    body: Joi.object({}),
    params: Joi.object({}),
    query: QueryDto,
});

module.exports = GetAllLogsDto;