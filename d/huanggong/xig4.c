// Room: /d/huanggong/xig4.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������ǹ�������ÿ����ԡ�ĵط����峺�ĳ�ˮ����������
���㡣����Χ������滨��ݣ�ʱ����֥��֮�ң�����Ϯ�ԣ���
ܰ���ǡ��ͷ׵Ļ���Ʈ�ڳ��ϣ��ƴ������У����������ڳ�����
ԡ������Ҳ�������ڳ��о������ԡһ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xig3",
]));
        set("no_clean_up", 0);
       
        setup();
        replace_program(ROOM);
}