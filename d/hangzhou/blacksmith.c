// Room: /d/hangzhou/blacksmith.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺子");
	set("long", @LONG
一走进门，一阵热浪扑面而来，你不由得倒退了两步，一个
彪形大汉精赤着上身，站在火炉旁，专心致志的打造着什么，丝
毫没有注意到你的到来。门边立着一块铁皮板(ban)。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongning",
]));


        set("item_desc", ([ /* sizeof() == 2 */
	"ban" :  "
收购兵器盔甲
修理(fix)兵器
配钥匙(pei key)\n
",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
