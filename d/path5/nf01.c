// Room: /d/path5/nf01.c

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
  "west" : __DIR__"na09",
  "east" : __DIR__"nf02",
]));
        set("outdoors", "path5");
        set("altitude", 300);
	setup();
	replace_program(ROOM);
}
