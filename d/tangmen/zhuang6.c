// Room: /d/tangmen/zhuang6.c

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
	"west" : __DIR__"zhuang5",
]));
	set(SAFE_ENV, 1);
	setup();
}

int valid_leave(object ob,string dir)
{
	int sk;

	if(dir == "down")
	{
		if(sk = ob->query_skill("dodge", 1) < 80)
			ob->improve_skill("dodge", sk+10);
		if(ob->query("combat_exp") < 100000)
			ob->add("combat_exp",20+random(20));
	}

	return 1;
}
