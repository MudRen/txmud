// Room: /d/path2/ch_k37.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������һ����������ϣ�·��������һ���ŵķ����֡����
�������������������졣��ʱ������ƥ�����������߾�������С
�ĵ����Ա���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_k36",
  "south" : __DIR__"ch_k38",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}