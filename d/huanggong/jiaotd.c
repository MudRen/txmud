// Room: /d/huanggong/jiaotd.c

inherit ROOM;

void create()
{
        set("short", "��̩��");
        set("long", @LONG
�����ǻʼұ��������ĵط����������ǽ�Ƿ���һ��ľ�Ƶ�
���ӣ�ԶԶ��ȥ������Կ��������ϴ���˶�ʮ�������Ƶĺ���
�������ŵĴ�ž������������ù������������濴����û��ʲ
ô�䱸��ʵ���ϴ���ڻ������أ�һ��С�ľ���������Σ�գ�Ȱ
�㻹�ǸϿ��뿪���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqg",
  "north" : __DIR__"kunng",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}