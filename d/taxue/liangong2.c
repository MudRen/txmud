// liangong2.c 练功房
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","练功房");
        set("long",@LONG
这里是花府的练功房，地面铺者厚实的青砖，墙上(wall)隐约有一些
图案，如果有兴趣，你不妨碍揣摩(chuaimo)一下，踏雪山庄的弟子多在这
里练功。这里也是踏雪山庄传授弟子武功的场所。南面飘来一阵阵饭菜的香
味。
LONG);

	set("exits",([
		"north" : __DIR__"wuchang2",
	]));

	set("item_desc",([
		"wall" : "墙上画着一些对打的小人。\n",
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
	c_skill=(int)me->query_skill("parry", 1);
        c_skill1=(int)me->query_skill("literate", 1);

        if (me->query("class")!="taxue")
        {
         tell_object(me,"你不是踏雪山庄弟子，无法领悟石壁内容。\n");
                return 1; 
        }

	if (c_skill1<10)
		return notify_fail("你的知识太少了,还看不懂上面的东西。\n");

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
        
	tell_object(me,"你面对着石壁静思良久，对拆招卸力似有所悟。\n");
	me->receive_damage("gin", 20);
        me->improve_skill("parry", random(10*me->query("int")));
	return 1;
}
