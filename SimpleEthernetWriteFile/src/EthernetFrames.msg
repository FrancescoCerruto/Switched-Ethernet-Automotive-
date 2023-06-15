packet EthernetFrame {
    string dst;	//6 byte
    string src;	//6 byte
    int ethertype;	//2 byte
    byteLength = 26; //6 Dst + 6 Src + 2 Ethtype + 4 CRC + 8 preambolo
};

//entry rooting
struct RelayTableEntry {
    string addr;
    int port;
};

class StaticRelayEntries extends cOwnedObject {
    RelayTableEntry entries[];
};