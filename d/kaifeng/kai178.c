// Room: /u/w/wangs/b/kai178.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������ӿ���������ܾ�û��ס�ˡ�����ʵ��Ŵ�������
�ܲ�������Ŀ��˿��࣬ǽ�ϵ��µ������ǻҳ���һֻ��������
��ȥ��Ժ�����Ӳݴ�����լ��ǽ������̦֩�����ԵüȻ�������
ɭ��������һ��ĳ��š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai176",
]));

	setup();
	replace_program(ROOM);
}
