// Room: /d/path2/ch_t27.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·������ϡ��س���һЩ�Ӳݣ�������
����������˾������Ե�ʮ�ֻ�����·���߼�ֻɽ�����ڳԲݣ�
�ֲ����������Ļ���Ұ���ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_t26",
  "west" : __DIR__"ch_t28",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}