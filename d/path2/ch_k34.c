// Room: /d/path2/ch_k34.c

inherit ROOM;

void create()
{
	set("short", "ƽ��");
	set("long", @LONG
������ƽ��λ�ڻƺ����Ͽ��⸮�ı��棬��ƺӶɿڲ���
��Զ��·��ʱ��һЩС����һЩ����֮���ʳƷ��Ƥ���ڴ�ζ
�����㲻��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k33",
  "southdown" : __DIR__"ch_k35",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
