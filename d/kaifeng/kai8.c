// Room: /wiz/louth/k/kai8.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����һ��СС����Ժ����ΧԺǽ���ʣ�ȴ����Ϊ�˷�����
���Ǹ���֮�ã������ڰ����쳣�������뷢�԰׵��������ڷ���
������׽��˺ɱ�������������ʯ���Ϸ�������������������
���м��һֻ���ӵ���¯��Ʈɢ��������̴�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai58",
]));
        set("objects",([
        __DIR__"npc/yizhe":2,
]));

	setup();
	replace_program(ROOM);
}
