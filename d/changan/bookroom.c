// bookroom <room.h> ���

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���ĸ�");
        set("long", @LONG
����һ���ģ����С����֣�һ���ű��������֮��������
��˵���е�ī�㣬�����������ص����ú����˸��ŵ����ʣ�ʹ��
��һ�����׵ĸо���һ���ţ�����Կ���������һ���ܴ�ġ���
ʥͼ(eikon)����������һ������(couplet)��������Ҳ�ɿ�����
�˵�������������ϰ����˸����鼮�������ģ��������Ҫ����
Ե��Ҳ�������ġ��ɴ��򱱳��ž����ϴ�֡�
LONG
        );

	set("night_long",@LONG
���ĸ������Ѿ������ˡ���̨�ߵİ������ϵ���һյС�͵ƣ�
һλ�������Ӿ��ŵƹ���ҡͷ���ԵĶ���һ���顣
LONG
);

	set("item_desc", ([
		"eikon": "����һ������൱ϸ�µĿ�ʥͼ������ڼڼ��������Ȼ\n"+
			 "���Բ²⵽�������ߣ�����һ���ӹӹ֮�����������\n"+
                         "�ĵط�ȴû��дʲô���֡�\n",
		"couplet": "      Զ������ر�\n"+
                           "      ����˼�δ����\n",
        ]) );

	set("exits", ([
		"west" :	__DIR__"wroad3",
]) );
	set("no_sleep_room",1);

	set("objects",([
		__DIR__"npc/shu_boss"	: 1,
]));
        setup();
}

void open_close_door(string msg,object user)
{
	// �����Ϊ���곣פӪҵԱ��
	object ob = present("boss zhang",this_object());

	// user Ϊ�˷����ڵ����֮һ.
	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"���ϰ��ߵ����ǰһ�Ϲ�˵����С�ſ����ˣ�����λ"+
			RANK_D->query_respect(user)+"��ҪЩʲô�飿\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"���ϰ�ǫ������˵������λ"+
			RANK_D->query_respect(user)+"�Բ���С��Ҫ�����ˣ���������������\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"������Ϣ�ˡ�\n"NOR);
		return;
	}
}