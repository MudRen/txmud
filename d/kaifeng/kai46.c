// Room: /u/w/wangs/b/kai46.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������˼�����ݶգ����и��������ϡ��˾ߣ�ǽ�ߵط�
���ż�ֻ��ɨ�ѡ�����������ڵ������ϣ���˵����͵���Ե�
���϶��ǲ�ͬ�Ĵ�������Կ��������������ͷ�ܶ�����˻֮��
�����ڶ�����ȥ��һƥ��������ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai45",
]));
        set("objects",([
        __DIR__"npc/maboss":1,
        __DIR__"npc/huoji":2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
