// Room: chengxf4.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����ǳ���ة�ฮ�����ȣ�һ�����Ǻܿ������ͨ��Զ����
�������߿�ʼ�����������ľ�ʿ���������ԣ���Ϊ��Զ��������
�����ˣ����Լ�ʹ��Ѿ���ͼ�Ժ����������Ҳ���ܵ��̲顣����
�����ǰ׻����ã�������ǰԺ��
LONG
	);

        set("exits", ([
  "east" : __DIR__"chengxf1",
  "west" : __DIR__"chengxf5",
]));
        set("outdoors","chengxf");
        setup();

	replace_program(ROOM);
}