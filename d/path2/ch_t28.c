// Room: /d/path2/ch_t28.c

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
  "east" : __DIR__"ch_t27",
  "southwest" : __DIR__"ch_t29",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_6" : 4,
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
