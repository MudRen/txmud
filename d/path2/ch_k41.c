// Room: /d/path2/ch_k41.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������һ����������ϣ�·��������һ���ŵķ����֡����
�������������������졣��ʱ������ƥ���������߾�������С
�ĵ����Ա����������������߲�Զ�����ǿ��⸮�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k40",
  "south" : __DIR__"ch_k42",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
