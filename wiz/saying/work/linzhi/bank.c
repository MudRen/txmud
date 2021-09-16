//bank.c 林芝村的钱庄
inherit BANK;
void create()
{
        set("short", "日升隆钱庄林芝分号");
        set("long", @LONG
日升隆钱庄生意做的很大，居然在这种中原人很少到的地方
都有了他们的分号。你仔细观察了一下，发现这里的生意并不兴
隆，他们为什么在这种地方还开店倒是令人费解。
LONG
);
        set("item_desc", ([
        "sign" :  "日升隆钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan           转账
",
]));
        set("no_beg", 1);
        set("objects",([
        __DIR__"npc/banker":1,        
]));
        set("exits", ([
        "south": __DIR__"lz_eroad1", 
]));
        setup();
}
