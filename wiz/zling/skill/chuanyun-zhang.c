[0m
// chuanyun-zhang.c ´©ÔÆ´ß»êÕÆ
/*
     ÕİÁúÌ½Ê× ½øÍË¾í±Û ²×º£ÁúÒ÷ ²¨ÀË¶ÙÊ×
¡¡¡¡ °ë´°¹ÛÓê ÍÃÆğ÷½Âä ³¹µØ×·Êó ÀÕÂíÌı·ç
¡¡¡¡ ¾ªÉßÓöµĞ Å­»¢ËÑÉ½ Ìá¹­×½ºü °×Ô³¶·º×
*/
[0m
inherit SKILL;
[0m
mapping *action = ({
([      "action" : "$NÒ»Ê½¡¸[51mÕİÁúÌ½Ê×[0m¡¹£¬ÓÒÊÖĞé»Î£¬×óÊÖÑïÆğ£¬Í»È»ÅÄÏò$nµÄĞØÇ°¶şÑ¨",
        "damage":50,
        "damage_type" : "ğöÉË"
]),
([      "action" : "$N²àÉíÒ»»Î£¬Ò»Ê½¡¸[51m½øÍË¾í±Û[0m¡¹£¬×óÊÖÄÃÏò$nµÄ¼çÍ·£¬ÓÒÈ­´òÏò$nµÄĞØ¿Ú",
        "damage":60,
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÒ»Ê½¡¸[51m¾ªÉßÓöµĞ[0m¡¹£¬ÓÒÊÖ»·Â£³É×¦£¬Ò»³öÊÖ¾ÍÏò¿Û$nµÄÑÊºíÒªº¦",
        "damage":70,
        "damage_type" : "ğöÉË"
]),
([      "action" : "$N×óÊÖĞéÕĞ£¬ÓÒÕÆÖ±Á¢£¬Ò»Ê½¡¸[51m²¨ÀË¶ÙÊ×[0m¡¹£¬´í²½Æ®³ö£¬¼²ÅÄ$nµÄÃæÃÅ",
        "damage":80,
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÊ¹Ò»Ê½¡¸[51m³¹µØ×·Êó[0m¡¹£¬×óÈ­ÉÏ¸ñ£¬ÓÒÊÖÌ½µ×Í»³ö£¬×¥Ïò$nµÄñÉ²¿",
        "damage":90,
        "skill_name" : "³¹µØ×·Êó",
        "damage_type" : "ğöÉË"
]),
([      "action" : "$NÒ»Ê½¡¸[51mÀÕÂíÌı·ç[0m¡¹£¬Ê®Ö¸ÉìËõ£¬ĞéĞéÊµÊµµØÏ®Ïò$nµÄÈ«ÉíÒªÑ¨",
        "damage":100,
        "damage_type" : "ÄÚÉË"
]),
([      "action" : "$NË«ÊÖ±§È­£¬Ò»Ê½¡¸[51mÅ­»¢ËÑÉ½[0m¡¹£¬ÕÆÓ°·­·É£¬Í¬Ê±Ïò$nÊ©³ö¾Å¾Å°ËÊ®Ò»ÕĞ",
        "damage":105,
        "damage_type" : "ÄÚÉË"
]),
([      "action" : "$NÒ»Ê½¡¸[51m°×Ô³¶·º×[0m¡¹£¬È­ÕĞÈôÒşÈôÏÖ£¬ÈôÓĞÈôÎŞ£¬¼±¼±µØÅÄÏò$nµÄµ¤Ìï",
        "damage":110,
        "damage_type" : "ÄÚÉË"
]),
});
[0m
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
[0m
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("Á·´©ÔÆ´ß»êÕÆ±ØĞë¿ÕÊÖ¡£\n");
        if ((int)me->query_skill("taxue-force", 1) < 1)
                return notify_fail("ÄãµÄÌ¤Ñ©Éñ¹¦»ğºò²»¹»£¬ÎŞ·¨Ñ§´©ÔÆ´ß»êÕÆ¡£\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·´©ÔÆ´ß»êÕÆ¡£\n");
        return 1;
}
[0m
[0m
[0m
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
[0m
int practice_skill(object me)
{
        if ((int)me->query("kee") < 15)
                return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
        if ((int)me->query("force") < 15)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»´©ÔÆ´ß»êÕÆ¡£\n");
        me->receive_damage("kee", 15);
        me->add("force", -15);
        return 1;
}
string perform_action_file(string action)
{
return CLASS_D("taxue") +"/chuanyun-zhang/" + action;
}
[0m
string *parry_msg = ({
        "$nÒ»ÕĞ¡¸[51mÌá¹­×½ºü[0m¡¹£¬Ë«ÕÆÅÄÏò$NÎÕ$wµÄÊÖÍó¡£\n",
});
[0m
string *unarmed_parry_msg = ({
        "$nË«±ÛÒ»Éì£¬Ò»ÕĞ¡¸[51mÍÃÆğ÷½Âä[0m¡¹£¬»¯½âÁË$NµÄ¹¥ÊÆ¡£\n",
});
[0m
int effective_level() { return 12;}
[0m
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
