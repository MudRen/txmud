// Room: /d/guozijian/chongzhi.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "崇志堂");
	set("long", @LONG
这里是崇志堂，是监生学习的地方，这里正有几个监生拿着
古书，端坐在书桌前，摇着脑袋，背诵论语。看来来这里时间不
长。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"shuaixing",
]));

	setup();
	replace_program(ROOM);
}
