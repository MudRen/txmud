// Room: /u/w/wangs/b/kai162.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
向阳街的尽头，一根三丈高的旗杆上，挑起了四盏斗大的灯
笼，每当暮色降临，这里灯火通明。各家院子中传出一片欢笑之
声，中间又夹着猜枚行令，唱曲闹酒，当真是笙歌处处，一片升
平景象。后松街就在它的东北方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"kai161",
  "west" : __DIR__"kai163",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
