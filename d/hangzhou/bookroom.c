// /d/hangzhou/bookroom.c

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ꡣ�ıߵ�����ϰ����˸����鼮��һ��40����
����������������ƹ���������һ����ʮ��ʷ�������ֱ�
�������������ý����ζ�������Ϲ���һ������(sign)��
LONG
	);

	set("night_long",@LONG
��������Ѿ������ˡ���̨�ߵİ������ϵ���һյС�͵ƣ�
����ϰ���ſ�������ϴ��
LONG
);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"   : __DIR__"minan01",
	]) );


	set("objects", ([
		__DIR__"npc/shu_boss" : 1,
]) );

	setup();

}

string look_sign(object me)
{
	if( random(2) )
		return "����д�����麣�����ڸ�����\n";
	else
		return "����д�����������лƽ��ݣ�\n";
}

void open_close_door(string msg,object user)
{
	// �����Ϊ���곣פӪҵԱ��
	object ob = present("boss liu",this_object());

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
