// Room: guodaoe8.c by pian
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long",@LONG
����һ�����������Ļ��ȣ������ϻ��Ķ��ǵ���������
�����Ǳ��ɵ�ʲô��ʰɡ����Ȼ���������ǰԺ��ǰԺ��ʵ����
һ����С�Ļ�԰������ˮ����ɢ�����ܲ�ľ��ʼ����������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"guodaoe7",
	"west" : __DIR__"guodaoe9",
	"north":__DIR__"jiufang",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}