// Room: /d/shaolin/e_square.c

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����������µĶ��㳡���㳡�ܴ�����һЩ�޴����¯��
��������������������Ů�ϵľ����㡣��Զ���ĳ����Ʒ��Ź�
â������ɮ�����������͡���������������Ժ�㳡�������ǽ���
�޵�������Ϸ��ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"rroad2",
  "north" : __DIR__"rroad3",
  "east" : __DIR__"jinnaluo",
  "west" : __DIR__"m_square",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
