// Room: /d/huanggong/wuyd.c

inherit ROOM;

void create()
{
        set("short", "��Ӣ��");
        set("long", @LONG
������ǻ�����ʱ���ͻ������д����յĵط�������ڷ���
һ�������ܣ�����ʮ�˰�����������ȫ�������������һ����
�Σ��������������ܿ����ʼҵ����ɣ��㿴���Ժ󲻽�Ҳ������
�ĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"daolu3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}