// Room: /d/death/road1.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
������һ���ƾɵ�Сͤ��ǰ�棬ͤ��������һ��Сľ�ƣ���
д�š�����ͤ������С�ӡ����ͷ��ȥ��һƬ��ɽ��ˮ����Լ��
���ܿ������ǳ�����������������Ⱥ������������ʱ���������
������Ȼ���¡���ǰ���ǻ����ɵ�һƬ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : "/d/death/road2",
		"south" : "/d/death/gateway",
	]));

	set("no_magic", 1);

	setup();
}