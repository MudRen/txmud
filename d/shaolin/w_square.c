// Room: /d/shaolin/w_square.c

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����������µ����㳡���㳡�����Ǻ��������ˣ���֪��һ
�����������޵ġ�������һ��޴��Τ������˫�ֶ��Ž�ħ��
�ơ�����������н�ɮһ��������Τ�����֪���������ǿ�����
�޵���Ժ�������㳡������������������Ժ�㳡�����ǹ�
��������Ҳ�ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lroad2",
  "north" : __DIR__"lroad3",
  "east" : __DIR__"m_square",
  "west" : __DIR__"6zumiao",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
