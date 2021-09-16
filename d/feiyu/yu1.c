// Room: /wiz/louth/a/yu1.c

inherit ROOM;

void create()
{
	set("short", "绯雨阁大门");
	set("long", @LONG
只见一扇们红色的大门耸立在你的面前，门前站着四位如花
似玉的姑娘。你心里不禁好生奇怪，为什么这四位如花似玉的姑
娘各个都是一身戎装呢？抬头一看，啊！你一下子明白了。原来
这里就是天下知名的绯雨阁！江湖上人人都知道：绯雨阁只收女
弟子，而且弟子各个都是身怀绝技，巾帼不让须眉。想到这里你
对门口的四位姑娘不禁肃然起敬。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shanlu9",
  "south" : __DIR__"yu2",
]));
	set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hu2" : 1,
  __DIR__"npc/hu1" : 1,
  __DIR__"npc/hu3" : 1,
  __DIR__"npc/hu4" : 1,
]));

	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me, string dir)
{
        object *inv;

        if(dir =="south"
        && (me->query("gender") == "男性")
	&& !wizardp(me) )
        {
		inv = all_inventory(this_object());

		foreach(object ob in inv)
			if(ob->id("hu wei") && living(ob))
				return notify_fail(sprintf("%s大喝一声：站住，绯雨阁禁止男性进入！\n",ob->name()));
        }
        return ::valid_leave(me, dir);
}
