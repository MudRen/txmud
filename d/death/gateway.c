// Room: /d/death/gateway.c

inherit ROOM;

void create()
{
	set("short", "�κ���");
	set("long", @LONG
������һ����֨�����������ľ���ϣ��ű���һ��Сľ�ƣ�
��д�š��κ��š�����˵�ߵ��������Ҳû���������ˡ�һ���
¡��¡������������(down)������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road1",
		"south" : "/d/death/gate",
	]));

	set( "item_desc", ([
		"down" : @LONG_TEXT
�㿿���űߣ�̽ͷ���ŵ�����ȥ�����û�ŵú��˳�����ֻ��һƬ����Ѫ��
�з������������Ƶĺ�ɫС�ߣ�Ѫ���ﻹ��һЩ��֪���˻���ʲ��Ķ�֫�к�����
Щ�˻���֪�������Ŵ�������Ҫ���ţ�ȴ���������������
LONG_TEXT
]) );
	set("no_magic", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail("һ���ն������������������....\n"+
			       "û�л�ͷ·��!\n");
	}
	else return 1;
}