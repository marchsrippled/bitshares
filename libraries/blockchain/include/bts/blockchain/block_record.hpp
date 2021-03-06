#pragma once

#include <bts/blockchain/block.hpp>

namespace bts { namespace blockchain {

   struct block_record : public bts::blockchain::digest_block
   {
      uint64_t          block_size = 0; /* Bytes */
      fc::microseconds  latency; /* Time between block timestamp and first push_block */

      share_type        signee_shares_issued = 0;
      share_type        signee_fees_collected = 0;
      share_type        signee_fees_destroyed = 0;
      fc::ripemd160     random_seed;

      fc::microseconds  processing_time; /* Time taken for extend_chain to run */
   };
   typedef optional<block_record> oblock_record;

   struct slot_record
   {
      slot_record(){} // Null case
      slot_record( const time_point_sec t, const account_id_type d, const optional<block_id_type>& b = optional<block_id_type>() )
      :start_time(t),block_producer_id(d),block_id(b){}

      bool is_null()const { return start_time == time_point_sec(); }

      time_point_sec            start_time;
      account_id_type           block_producer_id;
      optional<block_id_type>   block_id;
   };
   typedef fc::optional<slot_record> oslot_record;

} } // bts::blockchain

FC_REFLECT_DERIVED( bts::blockchain::block_record,
                    (bts::blockchain::digest_block),
                    (block_size)
                    (latency)
                    (signee_shares_issued)
                    (signee_fees_collected)
                    (signee_fees_destroyed)
                    (random_seed)
                    (processing_time)
                    )
FC_REFLECT( bts::blockchain::slot_record,
            (start_time)
            (block_producer_id)
            (block_id)
            )
