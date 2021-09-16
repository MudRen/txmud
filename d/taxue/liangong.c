// liangong.c
// by feng

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","练功房");
        set("long",@LONG
这里是踏雪山庄的练功房，地面铺者厚实的青砖，墙上(wall)隐约有一
些图案，如果有兴趣，你不妨碍揣摩(chuaimo)一下。踏雪山庄的弟子多在
这里练功。这里是踏雪山庄传授弟子武功的场所。东边是弟子休息室。
LONG);

	set("item_desc",([
		"wall" : "好象画着一些挥拳舞腿的小人。\n",
	]));

	set("exits",([
		"north" : __DIR__"wuchang1",
	]));
	setup();
}

void init()
{
	add_action("do_chuaimo","chuaimo");
}

int do_chuaimo(string arg)
{
	object me=this_player();
	int c_skill1,c_skill;
	
	if (arg!="wall") return 0;
        c_skill=(int)me->query_skill("unarmed", 1);
        c_skill1=(int)me->query_skill("literate", 1);
	if (c_skill1<10)
		return notify_fail("你的知识太少了,还看不懂上面的东西。\n");

        if (me->query("class")!="taxue")
        {
         tell_object(me,"你不是踏雪山庄弟子，无法领悟石壁内容。\n");
                return 1; 
        }

        if (me->query("gin")<20)
        {
         tell_object(me,"你太累了，现在无法领悟石壁内容。\n");
                return 1; 
        }

        if (c_skill>50)
        {
	tell_object(me,"你觉得石壁内容太肤浅了。\n");
                return 1; 
        }
        
	tell_object(me,"你面对着石壁静思良久，对基本拳术似有所悟。\n");
	me->receive_damage("gin", 20);
        me->improve_skill("unarmed", random(10*me->query("int")));
	return 1;
}
