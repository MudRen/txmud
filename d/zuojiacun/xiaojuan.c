// Room: /d/zuojiacun/xiaojuan.c

inherit ROOM;

void create()
{
	set("short", "��ŮС���");
	set("long", @LONG
����һ����ͨ�Ĳ��ݣ�ס����ŮС�������үү��С���Ǹ�
���µĺ��ӣ������һ�л������ڿ�������ά�֡����ڴ�С����
���߳���С���ˮ�Էǳ��ã���˵�����������κ������˵Ļ�
����������ັ���ı��ǡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu19",
]));

	setup();
	replace_program(ROOM);
}
