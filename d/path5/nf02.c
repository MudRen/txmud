// Room: /d/path5/nf02.c

inherit ROOM;

void create()
{
	set("short", "�ٻ���");
	set("long", @LONG
����һ�鳤���˸��ֻ��ݵ����֣�����ϵĸ�ʽ�����Ļ���
�У��ܶ��㶼�в�������������һ���������������㡣��Ȼ��
���ñ�����Щ�����̲�ס���˸����磬ԭ���ǻ��������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nf01",
  "east" : __DIR__"nf03",
]));
        set("outdoors", "path5");
        set("altitude", 300);
	setup();
	replace_program(ROOM);
}
