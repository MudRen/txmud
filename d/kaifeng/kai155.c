// Room: /u/w/wangs/b/kai155.c

inherit ROOM;

void create()
{
	set("short", "�ھֺ�Ժ");
	set("long", @LONG
���������ھֵ�ǰԺ�����þ��ܼ�����������ׯ��ȴ��һƬ
���ߵ��������أ�����һ���쳣�оɵ�С�ݣ��������޿����ع�
���š�С�ݱ�ֻ��ľ���ɣ��ŵú��裬����������������Ŀ�
϶�����硰ü��ɫ�衱�ش��ķ�����˻����롣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai150",
]));
        set("objects",([
        __DIR__"npc/tang": 1,
        __DIR__"npc/cb": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
