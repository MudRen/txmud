// Room: /d/huanggong/yusf.c

inherit ROOM;

void create()
{
        set("short", "���ŷ�");
        set("long", @LONG
��������������������ŷ��������ﵱ���ӵĶ������Ը���
������¥��������ÿ��Ѵ��ϱ����������ã����Ż��׹�����
Ʒ��������໹�Ǳ��˷ѵ��ˡ���ʹ������ȫϯҲ����ˡ�����
���ǵ����ջ�����ԭ����ô�á���ǰ�ķ�����ð��������������
ֱ����ˮ:).....����ס����Ҫ���һͨ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"daolu2",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}