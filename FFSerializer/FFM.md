This document roughly describes the very simple
format for serialized Final Frontier data, FFM (Final Frontier map).

FFM is saved as simple XML. Its implementation is based on TinyXML2.

The root node is called FFMap and contains all other nodes.
GameObject and Components are saved as nodes, their class members
are saved as attributes of the node. The attributes follow this format

    stringName = "stringValue"

Components are nested within the node of their GameObject.
References to GameObjects are serialized via the GameObjects' String ID.

The following is a simplified example of a FFM XML file.

<FFMap>
    <GameObject m_strID="go1" m_number="1">
        <Component m_go="go1" m_aFloat="0.1"/>
        <Component m_go="go1" m_aFloat="0.2"/>
    </GameObject>
    <GameObject m_strID="go2" m_number="2"/>
</FFMap>
