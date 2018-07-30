// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The CazCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions


static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(0, uint256("0x000008fef3a083a36208f4bcf73811d225bf70c0c25fced32b0e457ca75eab59"))
	(1000, uint256("0x0000001791bd8e4da8ccaebaff28b34ef4484f150f5e869b6a35e42a9ce02870"))
	(5000, uint256("0xc702646102e539852d5a1dbc19488ff99078d000ef1a31d7718294037f8c0c91"))
	(10000, uint256("0x1cc418c72666736a70c2adf35b1bc5c6fce07aca97b31af45d68761c3ab66912"))
	(20000, uint256("0x62a224ea22e767b354f1f0e5854c8f6da85216f22329c0f00a563c6f90351a4d"))
	(25550, uint256("0xb790cd6f25351bc9fbc711c58ecd97ea4585702a407ab938d7f09db7e41e4fb2"))
	(50000, uint256("0x18979aa918bf457765ecc9d4bbf761a0bfa656f6cb12dd0007e5ceebac811edd"))
	(80000, uint256("0x1bdefb98540a6a66da1ae7217e47d45d6de8a36a53869ddc9de869cb50321c26"))
	(110000, uint256("0x64532ec3abe8553d7e33b99c2a4db39c95bd674d2cf69d42d7642ab417d1308c"))
	(118800, uint256("0x43425e5ea2b977e11ddb9eb27b7ec2d923b5c616c7144b8d259f2cc3ee29732e"))
    (118811, uint256("0x3d63ebdb5463323fe2b3dc137fdcd8af92a671a3d7d770a2a5ec96c8608cd0f1"))
	(118900, uint256("0xedd57aa988c4a82bfaadf86b898e248b03e39222411bcad37616863458900a1e"));
    
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
	1532896389, // * UNIX timestamp of last checkpoint block
    0,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1454124731,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x3d;
        pchMessageStart[1] = 0xa2;
        pchMessageStart[2] = 0x32;
        pchMessageStart[3] = 0xb4;
        vAlertPubKey = ParseHex("04e4f228ef2bebe8da1bb14fdf8857d5c9c24ba72feb37da92efb3d84285df59c5c7316004091fb412b12d1cf0f901b440dac7a5e0d612bf8488abe0232c18bf9c");
        nDefaultPort = 17350;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 90; 
        nTargetSpacing = 1 * 90; 
        nLastPOWBlock = 2000;
        nMaturity = 50;
        nNewMaturity = 100;
        nProtocol_switch = 122760;
        nModifierUpdateBlock = 1;
		
        const char* pszTimestamp = "Copico to launch one of it's innovative products on the blockchain";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1523896200;
        genesis.nBits = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 206677;
		
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000008fef3a083a36208f4bcf73811d225bf70c0c25fced32b0e457ca75eab59"));
        assert(genesis.hashMerkleRoot == uint256("0x7dc06dd8c9bb15f1f4bfd39a96a9be72257b79fd591b67529c887cc8021d30f7"));
		
        vSeeds.push_back(CDNSSeedData("seed1.copico.io", "seed1.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed2.copico.io", "seed2.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed3.copico.io", "seed3.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed4.copico.io", "seed4.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed5.copico.io", "seed5.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed6.copico.io", "seed6.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed7.copico.io", "seed7.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed8.copico.io", "seed8.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed9.copico.io", "seed9.copico.io"));
        vSeeds.push_back(CDNSSeedData("seed10.copico.io", "seed10.copico.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 28);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 43);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 144);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x05).convert_to_container<std::vector<unsigned char> >();
		
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
		
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
		
        nPoolMaxTransactions = 3;
        strSporkKey = "04338280798413878bbb0499614330f3d8b209e369adff6f48ea51c212cbf426517eebd214af1bf47677d4a2dc74cf4362c9a45e0d86ee66e429a65dcca7d78a97";
        strObfuscationPoolDummyAddress = "CYiNW89nDmRdrFjhMA6SGLX3gjffrBLFdY";
        nStartMasternodePayments = 1523896200; //16 April 2018 16:30:00 GMT +00
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x4c;
        pchMessageStart[1] = 0x21;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xe1;
        vAlertPubKey = ParseHex("91000e1a09935a23f8e5af50b4a80b8b7d18abdab4f0e9bcf7c10857955f3c2c");
        nDefaultPort = 17351;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // CazCoin: 1 day
        nTargetSpacing = 1 * 60;  // CazCoin: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1454124731;
        genesis.nNonce = 2402015;
        hashGenesisBlock = genesis.GetHash();

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("seed11.copico.io", "seed11.copico.io"));
		
		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet cazcoin addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet cazcoin script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet cazcoin BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet cazcoin BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet cazcoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
		
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
		
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
		
        nPoolMaxTransactions = 2;
        strSporkKey = "04338280798413878bbb0499614330f3d8b209e369adff6f48ea51c212cbf426517eebd214af1bf47677d4a2dc74cf4362c9a45e0d86ee66e429a65dcca7d78a97";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // CazCoin: 1 day
        nTargetSpacing = 1 * 60;        // CazCoin: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 17355;

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
		
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;
static CChainParams* pCurrentParams = 0;
CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}
const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}
