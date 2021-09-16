// liangong.c
// by feng

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
        set("long",@LONG
������̤ѩɽׯ�����������������ߺ�ʵ����ש��ǽ��(wall)��Լ��һ
Щͼ�����������Ȥ���㲻������Ħ(chuaimo)һ�¡�̤ѩɽׯ�ĵ��Ӷ���
����������������̤ѩɽׯ���ڵ����书�ĳ����������ǵ�����Ϣ�ҡ�
LONG);

	set("item_desc",([
		"wall" : "������һЩ��ȭ���ȵ�С�ˡ�\n",
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
		return notify_fail("���֪ʶ̫����,������������Ķ�����\n");

        if (me->query("class")!="taxue")
        {
         tell_object(me,"�㲻��̤ѩɽׯ���ӣ��޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (me->query("gin")<20)
        {
         tell_object(me,"��̫���ˣ������޷�����ʯ�����ݡ�\n");
                return 1; 
        }

        if (c_skill>50)
        {
	tell_object(me,"�����ʯ������̫��ǳ�ˡ�\n");
                return 1; 
        }
        
	tell_object(me,"�������ʯ�ھ�˼���ã��Ի���ȭ����������\n");
	me->receive_damage("gin", 20);
        me->improve_skill("unarmed", random(10*me->query("int")));
	return 1;
}
