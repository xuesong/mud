inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������������ڵ�һ�������ĵĻ���·��������ЩС���ݣ�
��������ġ�·�����˺��٣�����ɫ�Ҵҵ���ǰ��·��
LONG);
        set("outdoors", "wudang");
        set("exits", ([
            "south"      : __DIR__"house",
            "southeast"  : __DIR__"wdroad5",
            "west"       : __DIR__"wdroad7",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}