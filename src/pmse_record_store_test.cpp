/*
 * Copyright 2014-2017, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "mongo/platform/basic.h"

#include <memory>
#include <sstream>
#include <string>
#include <time.h>

#include "mongo/base/checked_cast.h"
#include "mongo/base/init.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/db/concurrency/write_conflict_exception.h"
#include "mongo/db/json.h"
#include "mongo/db/operation_context_noop.h"
#include "mongo/db/storage/kv/kv_prefix.h"
#include "mongo/db/storage/record_store_test_harness.h"
#include "mongo/db/modules/pmse/src/pmse_record_store.h"
#include "mongo/stdx/memory.h"
#include "mongo/unittest/temp_dir.h"
#include "mongo/unittest/unittest.h"
#include "mongo/util/fail_point.h"
#include "mongo/util/scopeguard.h"

namespace mongo {
namespace {

using std::unique_ptr;
using std::string;
using std::stringstream;

TEST(PmseRecordStoreTest, Isolation1) {
    /*const auto harnessHelper(newRecordStoreHarnessHelper());
    unique_ptr<RecordStore> rs(harnessHelper->newNonCappedRecordStore());

    RecordId id1;
    RecordId id2;

    {
        ServiceContext::UniqueOperationContext opCtx(harnessHelper->newOperationContext());
        {
            WriteUnitOfWork uow(opCtx.get());

            StatusWith<RecordId> res = rs->insertRecord(opCtx.get(), "a", 2, Timestamp(), false);
            ASSERT_OK(res.getStatus());
            id1 = res.getValue();

            res = rs->insertRecord(opCtx.get(), "a", 2, Timestamp(), false);
            ASSERT_OK(res.getStatus());
            id2 = res.getValue();

            uow.commit();
        }
    }

    {
        ServiceContext::UniqueOperationContext t1(harnessHelper->newOperationContext());
        auto client2 = harnessHelper->serviceContext()->makeClient("c2");
        auto t2 = harnessHelper->newOperationContext(client2.get());

        unique_ptr<WriteUnitOfWork> w1(new WriteUnitOfWork(t1.get()));
        unique_ptr<WriteUnitOfWork> w2(new WriteUnitOfWork(t2.get()));

        rs->dataFor(t1.get(), id1);
        rs->dataFor(t2.get(), id1);

        ASSERT_OK(rs->updateRecord(t1.get(), id1, "b", 2, false, NULL));
        ASSERT_OK(rs->updateRecord(t1.get(), id2, "B", 2, false, NULL));

        try {
            // this should fail
            rs->updateRecord(t2.get(), id1, "c", 2, false, NULL).transitional_ignore();
            ASSERT(0);
        } catch (WriteConflictException& dle) {
            w2.reset(NULL);
            t2.reset(NULL);
        }

        w1->commit();  // this should succeed
    }*/
}

}  // namespace
}  // namespace mongo
