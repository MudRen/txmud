// Room: /d/huanggong/qianqg.c

inherit ROOM;

void create()
{
        set("short", "Ǭ�幬");
        set("long", @LONG
������ǻ���ÿ���糯��������µĵط���һ�ž޴����
���Ŵ������롣�����ϣ�һ���������۵ȴ�����ǰ�����ġ�
ǽ�Ϲ���һ���Ʋ������漣���������ֳ������ҵ����ɣ�һ����
��������ž��������ڿյĽ�����ʹ�˲�����������һ������ͷ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"daolu6",
  "south" : __DIR__"baohd",
  "north" : __DIR__"jiaotd",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

