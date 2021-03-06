#!/usr/bin/env bash
# Copyright 2020 Vectorized, Inc.
#
# Use of this software is governed by the Business Source License
# included in the file licenses/BSL.md
#
# As of the Change Date specified in that file, in accordance with
# the Business Source License, use of this software will be governed
# by the Apache License, Version 2.0


set -e

mkdir -p /mnt/vectorized/redpanda
mkdir -p /mnt/vectorized/back
rm -rf /mnt/vectorized/redpanda/* || true
rm -rf /mnt/vectorized/back/* || true
rm -rf /home/admin/redpanda.log || true
