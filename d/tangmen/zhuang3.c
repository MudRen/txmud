// Room: /d/tangmen/zhuang3.c

inherit __DIR__"zhuang";

void create()
{
	set("short", "梅花桩一");
	set("long", @LONG
一人多高的梅花桩，向下望去真让人心惊胆颤。
LONG
	);

	set("exits", ([
	"down" : __DIR__"lianwu",
	"east" : __DIR__"zhuang2",
	"southwest" : __DIR__"zhuang4",
]));
	set(SAFE_ENV, 1);
	setup();
}
