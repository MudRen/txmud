// liangong2.c ������
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
        set("long",@LONG
�����ǻ��������������������ߺ�ʵ����ש��ǽ��(wall)��Լ��һЩ
ͼ�����������Ȥ���㲻������Ħ(chuaimo)һ�£�̤ѩɽׯ�ĵ��Ӷ�����
������������Ҳ��̤ѩɽׯ���ڵ����书�ĳ���������Ʈ��һ���󷹲˵���
ζ��
LONG);

	set("exits",([
		"north" : __DIR__"wuchang2",
	]));

	set("item_desc",([
		"wall" : "ǽ�ϻ���һЩ�Դ��С�ˡ�\n",
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
         tell_object(me,"�㲻��̤ѩɽׯ���ӣ��޷�����ʯ�����ݡ�\n");
                return 1; 
        }

	if (c_skill1<10)
		return notify_fail("���֪ʶ̫����,������������Ķ�����\n");

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
        
	tell_object(me,"�������ʯ�ھ�˼���ã��Բ���ж����������\n");
	me->receive_damage("gin", 20);
        me->improve_skill("parry", random(10*me->query("int")));
	return 1;
}
