// Room: chengxf1.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
�����ǳ���ة�ฮ��ǰԺ���������Ų��ٵĴ�����һ��Сˮ
����������������ˮ���м�����Ժ������ɨ�ŵأ����������Ͼ�
���˴����ˣ�������ͨ�ž����������ȣ�����һ����������
�߾��Ǵ����ˡ�
LONG
	);

        set("exits", ([
  "south" : __DIR__"chengxf",
  "north" : __DIR__"chengxf6",
  "east" : __DIR__"chengxf2",
  "west" : __DIR__"chengxf4",
]));
        set("outdoors","chengxf");
	set("cannot_build_home",1);
	set("NORIDE","�Ҷ���ס��˵��������ة�ฮ���Ĺ��½Σ��������\n");

        setup();

	replace_program(ROOM);
}