// Room: /d/huanggong/kunng.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ǻʵ۴��ʱ�ͻʺ󶴷��ĵط����沼�õĸ����û�
�������̵����ɲ�˹�Ź����������ĵ�̺�������ǻ��ϵ���齣�
��һɫ�Ļ�ɫ�����ֳ������ҵ����ϡ��ǰ�ڷ���һ�Ű�������
����һ�״���Ĳ�ߣ��������⡣���������߾�����������԰��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiaotd",
  "north" : __DIR__"yuhy",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}