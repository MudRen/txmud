// Room: /d/path2/ch_k15.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
������ƽ̹�Ļ�������ϣ�������һ���޼ʵĻ�����ԭ��һ
Щũ�������������˸�������һ���������˲�һ������˷���
�ɴ����򱱾�����Ͽ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k11",
  "south" : __DIR__"ch_k16",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
