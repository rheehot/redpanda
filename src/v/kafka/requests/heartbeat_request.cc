// Copyright 2020 Vectorized, Inc.
//
// Use of this software is governed by the Business Source License
// included in the file licenses/BSL.md
//
// As of the Change Date specified in that file, in accordance with
// the Business Source License, use of this software will be governed
// by the Apache License, Version 2.0

#include "kafka/requests/heartbeat_request.h"

#include "kafka/groups/group_manager.h"
#include "kafka/groups/group_router.h"
#include "kafka/requests/request_context.h"
#include "kafka/requests/response.h"
#include "utils/remote.h"
#include "utils/to_string.h"

#include <seastar/core/print.hh>

namespace kafka {

ss::future<response_ptr> heartbeat_api::process(
  request_context&& ctx, [[maybe_unused]] ss::smp_service_group g) {
    return ss::do_with(std::move(ctx), [](request_context& ctx) {
        heartbeat_request request;
        request.decode(ctx.reader(), ctx.header().version);
        return ctx.groups()
          .heartbeat(std::move(request))
          .then([&ctx](heartbeat_response&& reply) {
              return ctx.respond(std::move(reply));
          });
    });
}

} // namespace kafka
