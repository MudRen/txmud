// Room: /d/huanggong/shenwm.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ǻʹ��ĵĺ��š�ÿ��ӱ��Ž���ʹ����˶�Ҫ����
����ߴ�ĳ�����Ϧ�����������Ե÷�����次���ɫ��������
���޴�����ɫ������ʾ�������ҵ����ɡ����ſ�һ�ӽ����ʿ
ʱ��ע���Ž����ʹ����ˡ����������Ͼ͵����հ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qinad",
  "north" : __DIR__"beim",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

