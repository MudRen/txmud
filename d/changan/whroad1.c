// /d/changan/whroad1  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
����ĳ����ǵ�����·���ǳ������������ֵ�֮һ��������
�ڽ��ڻʹ������Ǹ����ŵ����ڵ�����ʱʱ���䱸ɭ�ϣ�һ����
���ն���Ը������������������ǹ�Ѻ���ٵĵط�����ǰ��
�����塣����·�ɴ��������죬�����Ǳ���·��
LONG
        );

	set("exits", ([
		"west"		   : __DIR__"yushen",
                "north"            : __DIR__"nhroad4",
                "south"            : __DIR__"whroad2",
]) );

	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}
