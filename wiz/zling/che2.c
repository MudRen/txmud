// che3.c
// By dicky

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
�ɾ�����ĳ�����������λ�����ź�ɫ�Ľ��С���ǰ�ϳ�����������
�ظ����������е����������ڳ��ڣ�ȴ�����о��𵴡�͸���ĳ������ܹ���
�ʹ��������ľ�ɫ��
LONG
        );
        set("exits/out","/d/changan/yiguan");

        set("no_fight",1);

        setup();
}

void init()
{
        object me=this_player();
        string arg,arg1;
        object place = me->query_temp("place");
        if (!place){
         tell_object(me,YEL"\n�����������Դ�˵������Ҫȥ���ﰡ���ҿ����ˣ����˾������°ɰɡ�\n\n");
         return;
        }
        switch(place){
            case "ftc":      arg="/d/fengtian/out_fengtian_s";   arg1 ="�����"; break;
            case "zjc":      arg="/d/jinghai/zhuque6";           arg1 ="��Ҵ�"; break;
            case "myd":      arg="/d/jinghai/moon7";             arg1 ="���µ�"; break;
            case "pyz":      arg="/d/path1/py5";                 arg1 ="����կ"; break;
            case "dtf":      arg="/d/datong/minju3";             arg1 ="��ͬ��"; break;
            case "hfz":      arg="/d/heifeng/lu10";              arg1 ="�ڷ�կ"; break;
            case "tsz":      arg="/d/tianshui/cross";            arg1 ="��ˮ��"; break;
            case "hsp":      arg="/d/huashan_zx/guange3";        arg1 ="��ɽ��"; break;
            case "hyc":      arg="/d/huayin/daguchang";          arg1 ="������"; break;
            case "wcz":      arg="/d/wenchuan/fulai";            arg1 ="�봨��"; break;
            case "sls":      arg="/d/shaolin/tulu1";             arg1 ="������"; break;
            case "kff":      arg="/d/kaifeng/out_kaifeng_n";     arg1 ="���⸮"; break;
     case "cd":       arg="/d/chengdu/out_chengdu_n.c";  arg1 ="�ɶ�";   break;
            case "hzc":      arg="/d/hangzhou/out_hangzhou_n";   arg1 ="���ݳ�"; break;
            case "taxue":    arg="/d/houjizhen/shanya";          arg1 ="̤ѩɽׯ"; break;
            case "fyg":      arg="/d/feiyu/shanlu5";             arg1="����";  break;
            default: break;
        }
        set("exits/out",arg);
        message_vision(YEL "\n����Ѵ󳵿���·�ԣ�����˵����"+arg1+"�Ѿ����ˣ����³���out���ɡ�\n\n"NOR,me);
}

