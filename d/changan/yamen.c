// yamen  衙门

inherit ROOM;

void create()
{
        set("short", "京师衙门");
        set("long", @LONG
这里是长安府的所在，高大的门宸，门前两个巨大石狮子，
显得这里好不威严，门前有一个大鼓，这就是人们所说的鸣冤鼓。
门上两个巨大的门环，精美狴犴图案，象征的诉讼的意思，不过
如果没有什么冤情这样的地方还是少来为妙，你看，门前那两个
衙役正恶狠狠地瞪着你。从这里向东是白虎大街，向南就进了大
堂了。
LONG
        );

	set("exits", ([
                "east"             : __DIR__"whroad3",
                "south"            : __DIR__"big_room",
 ]) );

	set("cannot_build_home",1);
	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/yayi" : 2,
]));

	setup();
}