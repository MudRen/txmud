// Room: /d/path2/ch_k36.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������һ����������ϣ�·��������һ���ŵķ����֡����
�������������������졣��ʱ������ƥ���������߾�������С
�ĵ����Ա���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_k35",
  "southwest" : __DIR__"ch_k37",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
