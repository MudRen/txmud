// Room: /d/path2/ch_t24.c

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
  "north" : __DIR__"ch_t23",
  "south" : __DIR__"ch_t25",
]));

	set("outdoors", "path2");

	set("objects",([
	RIDE_DIR"w_horse" : 1,
]));

	setup();
	replace_program(ROOM);
}
