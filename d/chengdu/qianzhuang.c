// Room: /wiz/louth/c/qianzhuang.c

inherit BANK;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这里是成都的和记钱庄。和记钱庄拥有上百年的历史，现在
已经是江南数一数二的头号钱庄。门口的黑木牌子(paizi)上写着
几行字。从这里向西走就是武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao2",
]));
        set("item_desc", ([ /* sizeof() == 2 */
        "paizi" :  "本钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan           转账
",
]));

	set("objects",([
                __DIR__"npc/banker" :1,        
        ]));

	setup();
}
